# $NetBSD: Makefile,v 1.5 2008/10/19 19:18:30 he Exp $

P5_LIBINTL_VER=	1.16
DISTNAME=	libintl-perl-${P5_LIBINTL_VER}
PKGNAME=	p5-Locale-libintl-${P5_LIBINTL_VER}
PKGREVISION=	1
CATEGORIES=	misc perl5

CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=	peter.schuller@infidyne.com
HOMEPAGE=	http://search.cpan.org/dist/libintl-perl/
COMMENT=	Perl internationalization library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/libintl-perl/.packlist
CHECK_INTERPRETER_SKIP+=${PERL5_SUB_INSTALLVENDORLIB}/Locale/Recode.pm
CHECK_INTERPRETER_SKIP+=${PERL5_SUB_INSTALLVENDORLIB}/Locale/Recode/*.pm
CHECK_INTERPRETER_SKIP+=${PERL5_SUB_INSTALLVENDORLIB}/Locale/RecodeData.pm
CHECK_INTERPRETER_SKIP+=${PERL5_SUB_INSTALLVENDORLIB}/Locale/RecodeData/*.pm
CHECK_INTERPRETER_SKIP+=${PERL5_SUB_INSTALLVENDORLIB}/Locale/Messages.pm
CHECK_INTERPRETER_SKIP+=${PERL5_SUB_INSTALLVENDORLIB}/Locale/TextDomain.pm
CHECK_INTERPRETER_SKIP+=${PERL5_SUB_INSTALLVENDORLIB}/Locale/gettext_pp.pm
CHECK_INTERPRETER_SKIP+=${PERL5_SUB_INSTALLVENDORLIB}/Locale/gettext_xs.pod

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
