# $NetBSD: Makefile,v 1.1.1.1 2002/06/17 20:00:36 tron Exp $

DISTNAME=	esms-0.9.5
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=esms/}

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://esms.sourceforge.net/
COMMENT=	Command line SMS send tool

DEPENDS+=	perl>=5.6.1:../../lang/perl5
DEPENDS+=	p5-libwww>=5.64:../../www/p5-libwww
DEPENDS+=	p5-HTML-Parser>=3.25:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tree>=3.11:../../www/p5-HTML-Tree

GNU_CONFIGURE=	YES

REPLACE_PERL=	esms

.include "../../mk/bsd.pkg.mk"
