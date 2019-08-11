# $NetBSD: Makefile,v 1.94 2019/08/11 13:18:38 wiz Exp $
#
# When updating this package, please update mk/gnu-config/config.guess,
# mk/gnu-config/config.sub, and mk/gnu-config/missing as well.

DISTNAME=		autoconf-2.69
PKGREVISION=		9
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=		Generates automatic source code configuration scripts
LICENSE=		gnu-gpl-v3 AND gnu-fdl-v1.3

BUILD_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

# XXX: needs m4>1.4.6; wants m4>1.4.13
USE_TOOLS+=		gm4:run perl:run

# The next line is for conflicts with old versions of this package,
# which had autoconf-devel as PKGNAME.
CONFLICTS=		autoconf-devel-[0-9]*
# old versions of devel/gdb* installed standards.info as well.
CONFLICTS+=		gdb<5.3
CONFLICTS+=		gdb>6<6.2.1nb5

USE_LANGUAGES=		# empty
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-lispdir
CONFIGURE_ENV+=		ac_cv_prog_TEST_EMACS=no

TEXINFO_REQD=		4.0
INFO_FILES=		YES

AUTOMAKE_OVERRIDE=	NO

# [GNU Autoconf 2.67] testsuite: 213 268 269 failed
# 213?; other two ok because of buildlink
# [GNU Autoconf 2.69] testsuite: 281 282 failed
# 281: AC_NO_EXECUTABLES (working linker)              FAILED (c.at:221)
# 282: AC_NO_EXECUTABLES (broken linker)               FAILED (c.at:231)

TEST_TARGET=		check

CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/autoconf/autoconf.m4f
CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/autotest/autotest.m4f
CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/m4sugar/m4sugar.m4f
CHECK_WRKREF_SKIP+=	${PREFIX}/share/autoconf/m4sugar/m4sh.m4f

.include "../../mk/bsd.pkg.mk"
