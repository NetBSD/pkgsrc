# New ports collection makefile for:	uudeview
# Version Required:     0.5.9
# Date Created:		04 Aug 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $NetBSD: Makefile,v 1.3 1998/03/02 00:06:45 tron Exp $
# $FreeBSD Id: Makefile,v 1.15 1998/02/18 22:19:58 hoek Exp
#

DISTNAME=       uudeview-0.5.13
CATEGORIES=	converters
MASTER_SITES=	http://www.uni-frankfurt.de/~fp/uudeview/Apps/frank/  \
		ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/

MAINTAINER=	hoek@FreeBSD.ORG

LIB_DEPENDS=	uu.1.:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--enable-inews=inews --disable-tcl
CONFIGURE_ENV=	LDFLAGS=-s

MAN1=		uudeview.1 uuenview.1

PORTDOCDIR?=	share/doc/uudeview

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Copying documents to ${PREFIX}/${PORTDOCDIR}"
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
	@${INSTALL_MAN} ${WRKSRC}/HOWTO ${PREFIX}/${PORTDOCDIR}
	@${INSTALL_MAN} ${FILESDIR}/porting.notes ${PREFIX}/${PORTDOCDIR}
.else
	@${ECHO_MSG} "===>  Not copying available documents"
.endif

.include <bsd.port.mk>
