# $NetBSD: Makefile,v 1.1.1.1 2001/05/21 22:26:59 jtb Exp $

DISTNAME=	efax-0.9
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/serialcomm/fax/}

MAINTAINER=	packages@netbsd.org
COMMENT=	set of small programs for sending and receiving faxes

.include "../../mk/bsd.prefs.mk"

post-patch:
	${SED} -e 's:@PREFIX@:${PREFIX}:g;				\
		s:@LOCALBASE@:${LOCALBASE}:g;				\
		s:@SERIAL_DEVICE@:${DEFAULT_SERIAL_DEVICE:S,/dev/,,}:g'	\
	${WRKSRC}/fax > ${WRKSRC}/fax.tmp
	${MV} -f ${WRKSRC}/fax.1 ${WRKSRC}/fax.1.dist
	${SED} -e 's:@PREFIX@:${PREFIX}:g;				\
		s:@SERIAL_DEVICE@:${DEFAULT_SERIAL_DEVICE:S,/dev/,,}:g'	\
	${WRKSRC}/fax.1.dist > ${WRKSRC}/fax.1

# XXX  We need to split the `fax' script into `efax.rc' and a smaller
# `fax' script so that the user doesn't need to edit the script itself
# to set important variables.

	${HEAD} -n 5 ${WRKSRC}/fax.tmp > ${WRKSRC}/fax
	${TAIL} -n 649 ${WRKSRC}/fax.tmp >> ${WRKSRC}/fax
	${HEAD} -n 404 ${WRKSRC}/fax.tmp > ${WRKSRC}/efax.rc1
	${TAIL} -n 402 ${WRKSRC}/efax.rc1 > ${WRKSRC}/efax.rc

post-install:
	${INSTALL_DATA_DIR} /var/spool/efax
	${CHMOD} 755 /var/spool/efax
	${INSTALL_DATA_DIR} /var/log/efax
	${CHMOD} 755 /var/log/efax

.include "../../mk/bsd.pkg.mk"
