# $NetBSD: Makefile,v 1.11 2005/02/03 21:51:32 jlam Exp $

DISTNAME=	PostScript-MailLabels-2.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5psm
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PostScript/} \
		http://oplnk.net/~ajackson/software/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://oplnk.net/~ajackson/software/maillabels/
COMMENT=	Create PostScript for printing on mailing label stock

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PostScript/MailLabels/.packlist

REPLACE_PERL=		${WRKSRC}/demo/*.pl
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	for file in ${REPLACE_PERL}; do					\
		${INSTALL_SCRIPT} $$file ${EGDIR};			\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
