# $NetBSD: Makefile,v 1.4 2001/11/26 06:50:13 jlam Exp $

DISTNAME=	PostScript-MailLabels-1.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5psm
CATEGORIES=	print perl5
MASTER_SITES=	http://www.oplnk.net/~ajackson/software/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.oplnk.net/~ajackson/software/maillabels/
COMMENT=	create PostScript for printing on mailing label stock

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PostScript/MailLabels/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
