# $NetBSD: Makefile,v 1.17 2009/07/07 15:46:47 sno Exp $

DISTNAME=	AddressBook-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AddressBook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AddressBook/
COMMENT=	Perl5 module for unified access to addressbook databases
LICENSE=	artistic

DEPENDS+=	p5-DBI>=1.14:../../databases/p5-DBI
DEPENDS+=	p5-Date-Manip>=5.39:../../devel/p5-Date-Manip
DEPENDS+=	p5-XML-DOM>=1.25:../../textproc/p5-XML-DOM
DEPENDS+=	p5-perl-ldap>=0.20:../../databases/p5-perl-ldap
DEPENDS+=	p5-pilot-link-[0-9]*:../../comms/p5-pilot-link

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/AddressBook/.packlist

REPLACE_PERL=	examples/SyncAbook.pm
REPLACE_PERL+=	examples/abook.palm
REPLACE_PERL+=	examples/phonelist.cgi

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC};							\
	for file in ${REPLACE_PERL} examples/ldap-abook.conf; do	\
		${INSTALL_DATA} $${file} ${EGDIR};			\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
