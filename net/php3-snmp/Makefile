# $NetBSD: Makefile,v 1.2 2002/04/20 18:46:08 fredb Exp $

MODNAME=		snmp
CATEGORIES+=		net
PKGREVISION=		1
COMMENT=		PHP3 extension for SNMP database access

.include "../../www/php3/Makefile.module"

DEPENDS+=		ucd-snmp-4.2.4*:../../net/ucd-snmp

CONFIGURE_ARGS+=	--with-snmp=${LOCALBASE}
MOD_CPPFLAGS+=		-I${LOCALBASE}/include/ucd-snmp
MOD_CPPFLAGS+=		-I${WRKSRC}/dl
MOD_LIBS+=		-lsnmp

.include "../../mk/bsd.pkg.mk"
