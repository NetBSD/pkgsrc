# $NetBSD: Makefile,v 1.12 2002/03/15 17:05:37 skrll Exp $

DISTNAME=	eperl-2.2.14
CATEGORIES=	lang perl5 textproc
MASTER_SITES=	http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.engelschall.com/sw/eperl/
COMMENT=	Interpreter/preprocessor for Perl embedded in text documents

DEPENDS=	libperl>=${LIBPERL5_REQD}:../../lang/libperl

USE_PERL5=	# defined
LIBPERL5_REQD=	${PERL5_REQD}
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Parse/ePerl/.packlist

GNU_CONFIGURE=	# defined
ALL_TARGET=	all libeperl.a

AUTOMAKE_PATTERNS+=	config_ac.h.in

post-build:
	cd ${WRKSRC}/mod/Parse; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL
	cd ${WRKSRC}/mod/Parse; ${MAKE_PROGRAM}

post-install:
	cd ${WRKSRC}/mod/Parse; ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"
