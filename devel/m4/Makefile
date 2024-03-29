# $NetBSD: Makefile,v 1.82 2024/03/29 00:37:19 js Exp $

DISTNAME=	m4-1.4.19
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=m4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/m4/
COMMENT=	GNU version of UNIX m4 macro language processor
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--program-prefix=g
CONFIGURE_ARGS.Cygwin+=	ac_cv_func___fpending=yes
INFO_FILES=		yes
TEST_TARGET=		check

CFLAGS.AIX+=	-D_LINUX_SOURCE_COMPAT
.if ${MACHINE_ARCH} == "i386"
CFLAGS.QNX+=	-march=i486  # Defaults to i386 otherwise, which lacks atomics
.endif

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${DESTDIR}${PREFIX}/share/examples/m4
	${LN} -sf ${PREFIX}/bin/gm4 ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/m4
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/gm4.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/m4.1

.include "../../mk/bsd.pkg.mk"
