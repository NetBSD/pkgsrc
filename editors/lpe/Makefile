# $NetBSD: Makefile,v 1.8 2004/10/03 00:14:38 tv Exp $
#

DISTNAME=	lpe-1.2.6
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.sasknow.com/pub/ \
		ftp://ftp.twu.net/users/cdsmith/lpe/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cdsmith.twu.net/professional/opensource/lpe.html
COMMENT=	Small and efficient programmer's editor for UNIX systems

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_PKGINSTALL=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

SHLIBTOOL_OVERRIDE=	libtool

CONFIGURE_ENV=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"
MAKE_ENV=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"
CFLAGS=			-DPREFIX=\"\\\"${PREFIX}\\\"\"

post-patch:
	@cd ${WRKSRC}/man &&				\
	for f in cs de en es; do			\
		${MV} lpe.1.$${f} lpe.1.$${f}.orig;	\
		${SED} ${FILES_SUBST_SED} lpe.1.$${f}.orig > lpe.1.$${f}; \
	done

.include "../../devel/libslang/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
