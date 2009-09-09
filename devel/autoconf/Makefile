# $NetBSD: Makefile,v 1.69 2009/09/09 12:52:04 wiz Exp $

DISTNAME=		autoconf-2.64
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=autoconf/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=		Generates automatic source code configuration scripts
LICENSE=		gnu-gpl-v2 AND gnu-fdl-v1.3 # AND gnu-gpl-v3 for building

# XXX: needs m4>1.4.6; wants m4>1.4.13
USE_TOOLS+=		gm4:run perl:run

# The next line is for conflicts with old versions of this package,
# which had autoconf-devel as PKGNAME.
CONFLICTS=		autoconf-devel-[0-9]*
# old versions of devel/gdb6 installed standards.info as well.
CONFLICTS+=		gdb<6.2.1nb5

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

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

# wiz 20090809: next section commented out because it seems not to be needed.
# re-enable if it is; otherwise it will be removed during the next
# update:
# pkgsrc symlinks config/config.guess and config.sub to mk/gnu-config
# when you do not preserve timestamps in mk, this can cause
# config.guess and config.sub to be newer than config.guess.1 and
# config.sub.1.  In that case, the man pages need to be rebuilt, and
# build fails because pkgsrc lacks help2man.  Work around this situation.
#pre-build:
#	${TOUCH} ${WRKSRC}/man/config.sub.1 ${WRKSRC}/man/config.guess.1

.include "../../mk/bsd.pkg.mk"
