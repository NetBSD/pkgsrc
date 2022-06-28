# $NetBSD: Makefile,v 1.33 2022/06/28 11:31:19 wiz Exp $

DISTNAME=	AddressBook-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	19
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AddressBook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AddressBook
COMMENT=	Perl5 module for unified access to addressbook databases
LICENSE=	artistic

DEPENDS+=	p5-DBI>=1.14:../../databases/p5-DBI
DEPENDS+=	p5-Date-Manip>=5.39:../../devel/p5-Date-Manip
DEPENDS+=	p5-XML-DOM>=1.25:../../textproc/p5-XML-DOM
DEPENDS+=	p5-perl-ldap>=0.20:../../databases/p5-perl-ldap
DEPENDS+=	p5-pilot-link-[0-9]*:../../comms/p5-pilot-link

PERL5_PACKLIST=	auto/AddressBook/.packlist

REPLACE_PERL=	examples/SyncAbook.pm
REPLACE_PERL+=	examples/abook.palm
REPLACE_PERL+=	examples/phonelist.cgi

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS=	${EGDIR}

post-install:
	for file in ${REPLACE_PERL} examples/ldap-abook.conf; do	\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DESTDIR}${EGDIR};	\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
