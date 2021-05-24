# $NetBSD: Makefile,v 1.25 2021/05/24 19:52:43 wiz Exp $

GITHUB_PROJECT=	OpenDMARC
GITHUB_TAG=	rel-opendmarc-1-4-0-Beta1
DISTNAME=	rel-opendmarc-1-4-0-Beta1
PKGNAME=	opendmarc-1.4.0b1
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=trusteddomainproject/}
DIST_SUBDIR=	${GITHUB_PROJECT}

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
USE_TOOLS+=	perl autoconf automake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-milter=${BUILDLINK_PREFIX.libmilter}
CONFIGURE_ARGS+=	--with-spf
CONFIGURE_ARGS+=	--with-spf2-lib=${BUILDLINK_PREFIX.libspf2}/lib
CONFIGURE_ARGS+= --with-spf2-include=${BUILDLINK_PREFIX.libspf2}/include/spf2

REPLACE_PERL=	reports/opendmarc-expire.in
REPLACE_PERL+=	reports/opendmarc-import.in
REPLACE_PERL+=	reports/opendmarc-params.in
REPLACE_PERL+=	reports/opendmarc-reports.in

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	${EGDIR}

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize; aclocal; autoheader; automake -a --foreign -i; autoconf

post-install:
	${INSTALL_DATA} ${WRKSRC}/opendmarc/opendmarc.conf.sample \
		${DESTDIR}${EGDIR}/

.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mail/libspf2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
