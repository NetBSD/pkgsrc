# $NetBSD: Makefile,v 1.14 1999/08/15 11:07:13 tron Exp $
# FreeBSD Id: Makefile,v 1.18 1998/04/06 20:50:31 andreas Exp
#

DISTNAME=	ucd-snmp-3.6.1
PKGNAME=	ucd-snmp-3.6.1p1
CATEGORIES=	net
MASTER_SITES= 	ftp://ucd-snmp.ucdavis.edu/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ece.ucdavis.edu/ucd-snmp/

USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-defaults --with-libwrap --with-logfile="/var/log/snmpd"

# this might make it easier to use scotty's mibs, and local ones too
CONFIGURE_ARGS+=--with-mibdirs="${PREFIX}/share/snmp/mibs:${PREFIX}/lib/tnm2.1.8/mibs:/usr/local/share/snmp/mibs"

# deal with libwrap bogosity by providing these variables to programs which
# do not supply them:
post-extract:
	@${ECHO} 'int allow_severity, deny_severity;' >${WRKSRC}/snmplib/libwrap.c

post-install:
	@${MKDIR} ${PREFIX}/share/examples/ucd-snmp
	${INSTALL_DATA} ${WRKSRC}/etc/* ${PREFIX}/share/examples/ucd-snmp
	${INSTALL_DATA_DIR} ${PREFIX}/lib/snmp/dlmod

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
CFLAGS+=	-Dnetbsd1
.endif

.include "../../mk/bsd.pkg.mk"
