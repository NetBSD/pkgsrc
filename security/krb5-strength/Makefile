# $NetBSD: Makefile,v 1.2 2024/05/29 16:34:16 adam Exp $

DISTNAME=	krb5-strength-3.3
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://archives.eyrie.org/software/kerberos/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://www.eyrie.org/~eagle/software/krb5-strength/
COMMENT=	Kerberos kadmind strength checking plugin
LICENSE=	mit AND artistic

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:run pkg-config
REPLACE_PERL+=	tools/krb5-strength-wordlist tools/heimdal-history

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
