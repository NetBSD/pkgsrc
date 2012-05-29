# $NetBSD: Makefile,v 1.67 2012/05/29 21:44:45 cheusov Exp $

DISTNAME=	m4-1.4.16
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=m4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/m4/
COMMENT=	GNU version of UNIX m4 macro language processor
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INFO_FILES=		yes

TEST_TARGET=		check

CONFIGURE_ARGS+=	--program-prefix=g

.include "../../mk/bsd.prefs.mk"

.if ${LOWER_OPSYS} == "aix"
CFLAGS+=	-D_LINUX_SOURCE_COMPAT
.endif

INSTALLATION_DIRS+=	share/examples/m4 gnu/bin

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${DESTDIR}${PREFIX}/share/examples/m4
	${LN} -sf ../../bin/gm4 ${DESTDIR}${PREFIX}/gnu/bin/m4

.include "../../mk/bsd.pkg.mk"
