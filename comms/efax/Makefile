# $NetBSD: Makefile,v 1.18 2006/03/14 01:14:27 jlam Exp $

DISTNAME=	efax-0.9
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/serialcomm/fax/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cce.com/efax/
COMMENT=	Collection of small programs for sending and receiving faxes

CONFLICTS=	kdeutils<3.1

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

	${HEAD} -5 ${WRKSRC}/fax.tmp > ${WRKSRC}/fax
	${TAIL} -649 ${WRKSRC}/fax.tmp >> ${WRKSRC}/fax
	${HEAD} -404 ${WRKSRC}/fax.tmp > ${WRKSRC}/efax.rc1
	${TAIL} -402 ${WRKSRC}/efax.rc1 > ${WRKSRC}/efax.rc

.include "../../mk/bsd.pkg.mk"
