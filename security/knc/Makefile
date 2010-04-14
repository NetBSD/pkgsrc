# $NetBSD: Makefile,v 1.2 2010/04/14 20:15:27 elric Exp $
#

DISTNAME=	knc-1.6.1
CATEGORIES=	security net
MASTER_SITES=	http://oskt.secure-endpoints.com/downloads/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://oskt.secure-endpoints.com/knc.html
COMMENT=	Kerberised NetCat
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		nroff

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../mk/krb5.buildlink3.mk"
.if ${KRB5_TYPE} == "heimdal"
CFLAGS+=-DHEIMDAL
MAKE_ENV+=	LDADD=-lgssapi\ -lkrb5
.elif ${KRB5_TYPE} == "mit-krb5"
MAKE_ENV+=		LDADD=-lgssapi_krb5
.endif

.include "../../mk/bsd.pkg.mk"
