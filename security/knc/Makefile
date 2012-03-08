# $NetBSD: Makefile,v 1.3 2012/03/08 01:13:42 joerg Exp $
#

DISTNAME=	knc-1.6.1
CATEGORIES=	security net
MASTER_SITES=	http://oskt.secure-endpoints.com/downloads/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://oskt.secure-endpoints.com/knc.html
COMMENT=	Kerberised NetCat
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILD_DIRS=	bin
BUILD_TARGET=	knc

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/knc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/krb5.buildlink3.mk"
.if ${KRB5_TYPE} == "heimdal"
CFLAGS+=-DHEIMDAL
MAKE_ENV+=	LDADD=-lgssapi\ -lkrb5
.elif ${KRB5_TYPE} == "mit-krb5"
MAKE_ENV+=		LDADD=-lgssapi_krb5
.endif

.include "../../mk/bsd.pkg.mk"
