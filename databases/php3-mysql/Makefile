# $NetBSD: Makefile,v 1.1.1.1 2002/01/10 13:03:47 jlam Exp $

MODNAME=		mysql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP3 extension for MySQL database access

USE_BUILDLINK_ONLY=	yes

.include "../../www/php3/Makefile.module"

BUILDLINK_DEPENDS.mysql-client=	mysql-client>=3.23.35

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_DIR}
MOD_CPPFLAGS+=		-I${BUILDLINK_DIR}/include/mysql
MOD_LDFLAGS+=		-L${BUILDLINK_DIR}/lib/mysql -R${LOCALBASE}/lib/mysql
MOD_LIBS+=		-lmysqlclient -lm

.include "../../databases/mysql-client/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
