# $NetBSD: Makefile,v 1.26 2005/12/05 23:55:20 rillig Exp $

DISTNAME=	eperl-2.2.14
PKGREVISION=	3
CATEGORIES=	lang perl5 textproc
MASTER_SITES=	http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.engelschall.com/sw/eperl/
COMMENT=	Interpreter/preprocessor for Perl embedded in text documents

PERL5_PACKLIST=	auto/Parse/ePerl/.packlist

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
PERL5_CONFIGURE=	NO
PERL5_CONFIGURE_DIRS=	${WRKSRC}/mod/Parse
BUILD_DIRS=		${WRKSRC} ${WRKSRC}/mod/Parse

post-configure: perl5-configure

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
