# $NetBSD: Makefile,v 1.17 2003/06/02 01:16:42 jschauma Exp $

DISTNAME=	eperl-2.2.14
CATEGORIES=	lang perl5 textproc
MASTER_SITES=	http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.engelschall.com/sw/eperl/
COMMENT=	Interpreter/preprocessor for Perl embedded in text documents

USE_BUILDLINK2=	YES
LIBPERL5_REQD=	${PERL5_REQD}
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Parse/ePerl/.packlist

GNU_CONFIGURE=		YES
PERL5_CONFIGURE=	NO
PERL5_CONFIGURE_DIRS=	${WRKSRC}/mod/Parse
BUILD_DIRS=		${WRKSRC} ${WRKSRC}/mod/Parse

post-configure: perl5-configure

.include "../../lang/libperl/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
