# $NetBSD: Makefile,v 1.1 2012/10/07 18:52:17 bad Exp $

DISTNAME=	Fsdb-2.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/FSDB/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/FSDB/index.html
COMMENT=	Commands for manipulating flat-ASCII databases
LICENSE=	gnu-gpl-v2

CONFLICTS=	jdb-[0-9]*

USE_TOOLS+=		perl

DEPENDS+=	p5-HTML-Parser>=3.69:../../www/p5-HTML-Parser
DEPENDS+=	p5-Text-CSV_XS>=0.91:../../textproc/p5-Text-CSV_XS

PERL5_PACKLIST=		auto/Fsdb/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
