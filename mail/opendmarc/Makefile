# $NetBSD: Makefile,v 1.30 2022/07/02 13:02:32 taca Exp $

DISTNAME=	rel-${PKGNAME_NOREV:C/\./-/g}
PKGNAME=	opendmarc-1.4.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=trusteddomainproject/}
GITHUB_PROJECT=	OpenDMARC
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.trusteddomain.org/opendmarc/
COMMENT=	Open source DMARC library, MTA filter implementation and tools
LICENSE=	modified-bsd

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	p5-Switch-[0-9]*:../../lang/p5-Switch
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message

USE_LIBTOOL=	yes
USE_TOOLS+=	perl autoconf automake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-milter=${BUILDLINK_PREFIX.libmilter}
CONFIGURE_ARGS+=	--with-spf
CONFIGURE_ARGS+=	--with-spf2-lib=${BUILDLINK_PREFIX.libspf2}/lib
CONFIGURE_ARGS+=	--with-spf2-include=${BUILDLINK_PREFIX.libspf2}/include/spf2

LDFLAGS.SunOS+=	-lsocket -lnsl

TEST_TARGET=	check

REPLACE_PERL=	reports/opendmarc-expire.in
REPLACE_PERL+=	reports/opendmarc-import.in
REPLACE_PERL+=	reports/opendmarc-params.in
REPLACE_PERL+=	reports/opendmarc-reports.in

OPENDMARC_USER?=	opendmarc
OPENDMARC_GROUP?=	opendmarc
PKG_GROUPS=		${OPENDMARC_GROUP}
PKG_USERS=		${OPENDMARC_USER}:${OPENDMARC_GROUP}
PKG_GROUPS_VARS=	OPENDMARC_GROUP
PKG_USERS_VARS=		OPENDMARC_USER

PKG_GECOS.${OPENDMARC_USER}=	OpenDMARC user

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

FILES_SUBST+=	OPENDMARC_USER=${OPENDMARC_USER}
FILES_SUBST+=	OPENDMARC_GROUP=${OPENDMARC_GROUP}

RCD_SCRIPTS=	opendmarc
SMF_METHODS=	opendmarc

PKG_SYSCONFSUBDIR=	opendmarc

CONF_FILES+=	${EGDIR}/opendmarc.conf.sample ${PKG_SYSCONFDIR}/opendmarc.conf

INSTALLATION_DIRS=	${EGDIR}

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fiv

post-install:
	${SED} -e 's,/usr/local/etc/opendmarc,${PKG_SYSCONFDIR},g' \
		${WRKSRC}/opendmarc/opendmarc.conf.sample \
		> ${DESTDIR}${EGDIR}/opendmarc.conf.sample

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mail/libspf2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
