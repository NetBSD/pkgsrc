# $NetBSD: Makefile,v 1.20 2020/08/16 08:36:18 wiz Exp $

DISTNAME=	opendmarc-1.3.1
PKGREVISION=	8
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
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message

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

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
