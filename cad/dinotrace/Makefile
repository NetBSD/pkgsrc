# $NetBSD: Makefile,v 1.15 2002/02/18 15:14:02 seb Exp $
#

DISTNAME=	dinotrace-9.1g
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.com/ftp/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE= 	http://www.veripool.com/dinotrace/
COMMENT=	tool for viewing the output of digital simulators

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

INFO_FILES=	dinotrace.info

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
