# $NetBSD: Makefile,v 1.6 2005/04/05 10:40:37 wiz Exp $

DISTNAME=	qident-1.2
CATEGORIES=	security net
MASTER_SITES=	http://www.interlude.eu.org/~ad/software/download/qident/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.interlude.eu.org/~ad/software/qident/
COMMENT=	Small program to query an ident protocol server (rfc1413)

MANCOMPRESSED_IF_MANZ=	YES

.include "../../security/libident/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
