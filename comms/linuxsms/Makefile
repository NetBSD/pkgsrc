# $NetBSD: Makefile,v 1.3 2003/06/13 15:17:07 jmmv Exp $
#

DISTNAME=	linuxsms-0.65
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linuxsms/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://linuxsms.sourceforge.net/
COMMENT=	Perl script to send short messages to GSM phones

USE_BUILDLINK2=	yes
USE_PERL5=	yes
NO_BUILD=	yes

REPLACE_PERL=	${WRKSRC}/linuxsms

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/linuxsms ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/linuxsms.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/linuxsms
.for f in BUGS CHANGES README README.ES TODO
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/linuxsms
.endfor
.undef f

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
