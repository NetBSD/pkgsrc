# $NetBSD: Makefile,v 1.6 2004/01/12 09:46:04 cjep Exp $
#

DISTNAME=	sympa-3.4.2
CATEGORIES=	mail
MASTER_SITES=	http://www.sympa.org/distribution/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.sympa.org/
COMMENT=	Mailing list manager

DEPENDS+=	p5-CGI>=2.52:../../www/p5-CGI
DEPENDS+=	p5-FCGI>=0.48:../../www/p5-FCGI
DEPENDS+=	p5-Digest-MD5>=2.00:../../security/p5-Digest-MD5
DEPENDS+=	p5-IO-stringy>=1.0:../../devel/p5-IO-stringy
DEPENDS+=	p5-Msgcat>=1.01:../../misc/p5-Msgcat
DEPENDS+=	p5-MIME-Base64>=1.0:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MIME-tools>=5.209:../../mail/p5-MIME-tools
DEPENDS+=	p5-MailTools>=1.32:../../mail/p5-MailTools
DEPENDS+=	p5-DBI>=1.06:../../databases/p5-DBI
DEPENDS+=	p5-DBD-Sybase>=0.90:../../databases/p5-DBD-Sybase
DEPENDS+=	p5-DBD-mysql>=2.0407:../../databases/p5-DBD-mysql
DEPENDS+=	p5-DBD-postgresql>=0.90:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-perl-ldap>=0.10:../../databases/p5-perl-ldap
DEPENDS.SunOS+=	p5-DB_File-[0-9]*:../../databases/p5-DB_File

OPSYSVARS+=	DEPENDS

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-piddir=/var/run

PERL5_REQD=	5.005

PKG_GROUPS?=	sympa
PKG_USERS?=	sympa:sympa

# We do not support set-uid scripts...
post-install:
	${CHMOD} ug-s ${PREFIX}/bin/wwsympa.fcgi

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

PREFIX=	${LOCALBASE}/sympa
