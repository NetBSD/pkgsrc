# $NetBSD: Makefile,v 1.55 2005/06/15 13:27:15 wiz Exp $

DISTNAME=		autoconf-2.59
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=autoconf/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=		Generates automatic source code configuration scripts

USE_TOOLS+=		gm4
TOOLS_DEPMETHOD.gm4=	DEPENDS

# The next line is for conflicts with old versions of this package,
# which had autoconf-devel as PKGNAME.
CONFLICTS=		autoconf-devel-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-lispdir

INFO_FILES=		autoconf.info standards.info

PERL5_REQD+=		5.6
TEXINFO_REQD=		4.0

AUTOMAKE_OVERRIDE=	NO

TEST_TARGET=		check

CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/autoconf/autoconf.m4f
CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/autotest/autotest.m4f
CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/m4sugar/m4sugar.m4f
CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/m4sugar/m4sh.m4f

# undo a rather stupid hack in the install step when --without-lispdir is used
post-install:
	${RM} -rf ${WRKSRC}/lib/emacs/no

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
