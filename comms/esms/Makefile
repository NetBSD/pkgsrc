# $NetBSD: Makefile,v 1.3 2003/01/03 15:26:55 jmmv Exp $

DISTNAME=	esms-0.9.5
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=esms/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://esms.sourceforge.net/
COMMENT=	Command line SMS send tool

DEPENDS+=	p5-libwww>=5.64:../../www/p5-libwww
DEPENDS+=	p5-HTML-Parser>=3.25:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tree>=3.11:../../www/p5-HTML-Tree

GNU_CONFIGURE=	YES

USE_PERL5=	YES
PERL5_REQD?=	5.6.1
REPLACE_PERL=	esms

.include "../../mk/bsd.pkg.mk"
