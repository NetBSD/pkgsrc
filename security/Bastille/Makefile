# $NetBSD: Makefile,v 1.22 2022/06/28 11:35:33 wiz Exp $
#

DISTNAME=	Bastille-3.0.9
PKGREVISION=	11
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bastille-linux/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bastille-linux.sourceforge.net/
COMMENT=	System hardening tool focusing on educating the user

WRKSRC=			${WRKDIR}/Bastille
CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX:Q}/share/gconf/schemas/
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR=${PREFIX:Q}/share/gconf/schemas/
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none
USE_TOOLS+=		bash:run perl:run
NO_BUILD=		yes

CHECK_INTERPRETER_SKIP+=	share/Bastille/bastille-tmpdir.csh

BUILD_DEPENDS+=		checkperms>=1.4:../../sysutils/checkperms
DEPENDS+=		p5-Tk-[0-9]*:../../x11/p5-Tk

SUBST_CLASSES+=		b
SUBST_STAGE.b=		pre-configure
SUBST_FILES.b=		Install.sh
SUBST_SED.b=		-e 's,umask 077,umask 022,'
SUBST_SED.b+=		-e 's,\$$RPM_BUILD_ROOT/usr/,${DESTDIR}${PREFIX}/,g'
SUBST_SED.b+=		-e 's,\$$RPM_BUILD_ROOT/var/,${DESTDIR}${VARBASE}/,g'

SUBST_CLASSES+=		b2
SUBST_STAGE.b2=		pre-configure
SUBST_FILES.b2=		bin/bastille Bastille/API.pm
SUBST_VARS.b2=		PKG_SYSCONFDIR
SUBST_VARS.b2+=		PREFIX
SUBST_VARS.b2+=		VARBASE

SUBST_CLASSES+=		b3
SUBST_STAGE.b3=		pre-configure
SUBST_FILES.b3=		${REPLACE_PERL}
SUBST_SED.b3=		-e 's,^use lib.*,use lib "${PREFIX}/lib";,'
SUBST_NOOP_OK.b3=	yes # some of the files don't match

REPLACE_PERL+=		AutomatedBastille BastilleBackEnd BastilleChooser
REPLACE_PERL+=		InteractiveBastille RevertBastille *.pm
REPLACE_BASH+=		bin/bastille

BUILD_DEFS+=		VARBASE

OSMAP_FILES=		NetBSD.system.in NetBSD.bastille.in
OSMAP_SUBSTVARS=	PKG_SYSCONFDIR PREFIX VARBASE

post-extract:
	cd ${WRKSRC} && find . -print | checkperms -ffc
	cd ${FILESDIR} && cp ${OSMAP_FILES} ${WRKSRC}/OSMap/.

post-configure:
	set -e; cd ${WRKSRC}/OSMap; for i in ${OSMAP_FILES:.in=}; do sed ${OSMAP_SUBSTVARS:@v@-e 's,\@${v}\@,${${v}},g' @} < "$$i.in" > "$$i"; done

do-install:
	cd ${WRKSRC} && sh ./Install.sh

.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
