# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:31 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1996/11/21 11:27:26 asami Exp
#

DISTNAME=	mm2.7
PKGNAME=	mm-2.7
CATEGORIES=	mail
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	torstenb@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAN1= 		audiocompose.1 audiosend.1 extcompose.1 \
		getfilename.1 mailto-hebrew.1 mailto.1 metamail.1 \
		metasend.1 mime.1 mimencode.1 mmencode.1 \
		patch-metamail.1 richtext.1 showaudio.1 \
		showexternal.1 shownonascii.1 showpartial.1 \
		showpicture.1 splitmail.1
MAN4=		mailcap.4

post-patch:
	${RM} -f ${WRKDIR}/mm2.7/src/bin/*.orig

.include "../../mk/bsd.pkg.mk"
