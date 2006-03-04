# $NetBSD: Makefile,v 1.15 2006/03/04 21:30:31 jlam Exp $

DISTNAME=	PostScript-MailLabels-2.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5psm
PKGREVISION=	1
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PostScript/} \
		http://oplnk.net/~ajackson/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oplnk.net/~ajackson/software/maillabels/
COMMENT=	Create PostScript for printing on mailing label stock

PERL5_PACKLIST=		auto/PostScript/MailLabels/.packlist

REPLACE_PERL=		${WRKSRC}/demo/*.pl
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	for file in ${REPLACE_PERL}; do					\
		${INSTALL_SCRIPT} $$file ${EGDIR};			\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
