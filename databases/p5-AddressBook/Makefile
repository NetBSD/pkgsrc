# $NetBSD: Makefile,v 1.7 2004/04/27 02:27:36 snj Exp $

DISTNAME=	AddressBook-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=perl-abook/} \
		ftp://ftp.loaded.net/pub/CPAN/authors/id/D/DL/DLEIGH/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://perl-abook.sourceforge.net/
COMMENT=	Perl5 module for unified access to addressbook databases

DEPENDS+=	p5-DBI>=1.14:../../databases/p5-DBI
DEPENDS+=	p5-Date-Manip>=5.39:../../devel/p5-Date-Manip
DEPENDS+=	p5-XML-DOM>=1.25:../../textproc/p5-XML-DOM
DEPENDS+=	p5-perl-ldap>=0.20:../../databases/p5-perl-ldap
DEPENDS+=	p5-pilot-link-[0-9]*:../../comms/p5-pilot-link

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/AddressBook/.packlist

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
