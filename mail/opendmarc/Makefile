# $NetBSD: Makefile,v 1.13 2016/03/05 11:27:50 jperkin Exp $

DISTNAME=	opendmarc-1.3.1
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opendmarc/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.trusteddomain.org/opendmarc/
COMMENT=	Open source DMARC library, MTA filter implementation and tools
LICENSE=	modified-bsd

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
#DEPENDS+=	{perl>=5.6.1,p5-File-Temp-[0-9]*}:../../devel/p5-File-Temp
DEPENDS+=	p5-Switch-[0-9]*:../../lang/p5-Switch

RCD_SCRIPTS=	opendmarc

USE_LIBTOOL=	yes
USE_TOOLS+=	perl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-milter=${BUILDLINK_PREFIX.libmilter}

REPLACE_PERL=	reports/opendmarc-expire.in
REPLACE_PERL+=	reports/opendmarc-import.in
REPLACE_PERL+=	reports/opendmarc-params.in
REPLACE_PERL+=	reports/opendmarc-reports.in

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/opendmarc/opendmarc.conf.sample \
		${DESTDIR}${EGDIR}/

BUILDLINK_API_DEPENDS.openssl+=		openssl>=0.9.8
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
