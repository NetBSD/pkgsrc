# $NetBSD: Makefile,v 1.53 2007/06/15 18:15:06 jlam Exp $

DISTNAME=	minicom-2.1
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://alioth.debian.org/download.php/123/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alioth.debian.org/projects/minicom/
COMMENT=	MS-DOS Telix serial communication program "workalike"

DEPENDS+=	gkermit-[0-9]*:../../comms/gkermit
DEPENDS+=	lrzsz-[0-9]*:../../comms/lrzsz

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR=	minicom
EGDIR=			${PREFIX}/share/examples/minicom

PKG_GROUPS=		dialer
PKG_USERS=		uucp:dialer
SPECIAL_PERMS=		${PREFIX}/bin/minicom uucp dialer 4555
OWN_DIRS_PERMS=		${PKG_SYSCONFDIR} uucp dialer 0755
CONF_FILES_PERMS=	${EGDIR}/minicom.users ${PKG_SYSCONFDIR}/minicom.users \
			uucp dialer 0644

SUBST_CLASSES+=	minicom
SUBST_MESSAGE.minicom=	Fixing hardcoded paths.
SUBST_STAGE.minicom=	post-patch
SUBST_FILES.minicom=	src/rwconf.c
SUBST_SED.minicom=	-e 's,@PREFIX@,${PREFIX},g'

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/minicom.users ${EGDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
