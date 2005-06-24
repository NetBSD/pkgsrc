# $NetBSD: Makefile,v 1.22 2005/06/24 05:56:26 jlam Exp $

DISTNAME=	eperl-2.2.14
PKGREVISION=	1
CATEGORIES=	lang perl5 textproc
MASTER_SITES=	http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.engelschall.com/sw/eperl/
COMMENT=	Interpreter/preprocessor for Perl embedded in text documents

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Parse/ePerl/.packlist

GNU_CONFIGURE=		YES
PERL5_REQD+=		5.8.0
PERL5_CONFIGURE=	NO
PERL5_CONFIGURE_DIRS=	${WRKSRC}/mod/Parse
BUILD_DIRS=		${WRKSRC} ${WRKSRC}/mod/Parse

post-configure: perl5-configure

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
