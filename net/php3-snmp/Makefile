# $NetBSD: Makefile,v 1.1.1.1 2002/01/10 13:08:17 jlam Exp $

MODNAME=		snmp
CATEGORIES+=		net
PKGREVISION=		# empty
COMMENT=		PHP3 extension for SNMP database access

.include "../../www/php3/Makefile.module"

DEPENDS+=		ucd-snmp-[0-9]*:../../net/ucd-snmp

CONFIGURE_ARGS+=	--with-snmp=${LOCALBASE}
MOD_CPPFLAGS+=		-I${LOCALBASE}/include/ucd-snmp
MOD_CPPFLAGS+=		-I${WRKSRC}/dl
MOD_LIBS+=		-lsnmp

.include "../../mk/bsd.pkg.mk"
