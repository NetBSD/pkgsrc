# $NetBSD: Makefile,v 1.7 2003/07/21 17:16:26 martti Exp $

DISTNAME=	PostScript-MailLabels-1.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5psm
CATEGORIES=	print perl5
MASTER_SITES=	http://www.oplnk.net/~ajackson/software/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.oplnk.net/~ajackson/software/maillabels/
COMMENT=	Create PostScript for printing on mailing label stock

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PostScript/MailLabels/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
