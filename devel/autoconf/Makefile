# $NetBSD: Makefile,v 1.61.2.1 2006/11/07 07:55:30 ghen Exp $

DISTNAME=		autoconf-2.60
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=autoconf/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=		Generates automatic source code configuration scripts

USE_TOOLS+=		gm4:run perl:run

# The next line is for conflicts with old versions of this package,
# which had autoconf-devel as PKGNAME.
CONFLICTS=		autoconf-devel-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-lispdir

TEXINFO_REQD=		4.0
INFO_FILES=		YES

AUTOMAKE_OVERRIDE=	NO

TEST_TARGET=		check

CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/autoconf/autoconf.m4f
CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/autotest/autotest.m4f
CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/m4sugar/m4sugar.m4f
CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/m4sugar/m4sh.m4f

# pkgsrc symlinks config/config.guess and config.sub to mk/gnu-config
# when you do not preserve timestamps in mk, this can cause
# config.guess and config.sub to be newer than config.guess.1 and
# config.sub.1.  In that case, the man pages need to be rebuilt, and
# build fails because pkgsrc lacks help2man.  Work around this situation.
pre-build:
	${TOUCH} ${WRKSRC}/man/config.sub.1 ${WRKSRC}/man/config.guess.1

# undo a rather stupid hack in the install step when --without-lispdir is used
post-install:
	${RM} -rf ${WRKSRC}/lib/emacs/no

.include "../../mk/bsd.pkg.mk"
