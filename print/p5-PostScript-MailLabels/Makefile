# $NetBSD: Makefile,v 1.1.1.1 2001/09/29 06:17:27 jlam Exp $

DISTNAME=	PostScript-MailLabels-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	http://www.oplnk.net/~ajackson/software/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.oplnk.net/~ajackson/software/maillabels/
COMMENT=	create PostScript for printing on mailing label stock

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/PostScript/MailLabels/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
