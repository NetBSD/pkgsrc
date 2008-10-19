# $NetBSD: Makefile,v 1.18 2008/10/19 19:18:44 he Exp $

DISTNAME=	PostScript-MailLabels-2.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5psm
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PostScript/} \
		http://oplnk.net/~ajackson/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oplnk.net/~ajackson/software/maillabels/
COMMENT=	Create PostScript for printing on mailing label stock

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/PostScript/MailLabels/.packlist

REPLACE_PERL=		${WRKSRC}/demo/*.pl
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	${EGDIR}

post-install:
	for file in ${REPLACE_PERL}; do					\
		${INSTALL_SCRIPT} $$file ${DESTDIR}${EGDIR};		\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
