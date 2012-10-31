# $NetBSD: Makefile,v 1.69 2012/10/31 11:17:27 asau Exp $

DISTNAME=	m4-1.4.16
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=m4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/m4/
COMMENT=	GNU version of UNIX m4 macro language processor
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
INFO_FILES=		yes

TEST_TARGET=		check

CONFIGURE_ARGS+=	--program-prefix=g

.include "../../mk/bsd.prefs.mk"

.if ${LOWER_OPSYS} == "aix"
CFLAGS+=	-D_LINUX_SOURCE_COMPAT
.endif

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${DESTDIR}${PREFIX}/share/examples/m4
	${LN} -sf ${PREFIX}/bin/gm4 ${DESTDIR}${PREFIX}/gnu/bin/m4
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/gm4.1 ${DESTDIR}${PREFIX}/gnu/man/man1/m4.1

.include "../../mk/bsd.pkg.mk"
