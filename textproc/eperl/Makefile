# $NetBSD: Makefile,v 1.14 2002/10/28 00:22:03 seb Exp $

DISTNAME=	eperl-2.2.14
CATEGORIES=	lang perl5 textproc
MASTER_SITES=	http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.engelschall.com/sw/eperl/
COMMENT=	Interpreter/preprocessor for Perl embedded in text documents

DEPENDS=	{libperl>=${LIBPERL5_REQD},perl>=5.8.0}:../../lang/libperl

USE_BUILDLINK2=	YES
LIBPERL5_REQD=	${PERL5_REQD}
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Parse/ePerl/.packlist

GNU_CONFIGURE=	# defined
PERL5_CONFIGURE=	NO
PERL5_CONFIGURE_DIRS=	${WRKSRC}/mod/Parse
BUILD_DIRS=		${WRKSRC} ${WRKSRC}/mod/Parse

AUTOMAKE_PATTERNS+=	config_ac.h.in

post-configure: perl5-configure

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
