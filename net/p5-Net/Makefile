# $NetBSD: Makefile,v 1.5 1998/04/20 11:56:30 frueauf Exp $
# FreeBSD Id: Makefile,v 1.13 1997/06/27 18:38:15 jfitz Exp
#

DISTNAME=		libnet-1.0505
PKGNAME=		p5-Net-1.0505
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net

MAINTAINER=		packages@netbsd.org

BUILD_DEPENDS= 		${PREFIX}/lib/perl5/site_perl/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper

USE_PERL5=		YES

MAN3=			Net::Time.3 Net::DummyInetd.3 Net::NNTP.3 Net::SNPP.3 \
			Net::POP3.3 Net::Cmd.3 Net::SMTP.3 Net::Domain.3 \
			Net::FTP.3 Net::Netrc.3 Net::PH.3
MANPREFIX=		${PREFIX}/lib/perl5

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
