# $NetBSD: Makefile,v 1.37 2022/06/28 11:35:34 wiz Exp $

DISTNAME=	dnssec-tools-2.2.3
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=DNSSEC-Tools/}
GITHUB_PROJECT=	DNSSEC-Tools
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.dnssec-tools.org/
COMMENT=	Toolkit to ease the deployment of DNSSEC related technologies
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}/dnssec-tools

DEPENDS+=	p5-Net-DNS-SEC-[0-9]*:../../security/p5-Net-DNS-SEC
DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple

CONFLICTS=	gethost-[0-9]*

BUILD_DEFS+=	IPV6_READY

USE_TOOLS+=	perl

REPLACE_PERL+=	tools/modules/realm.pm
REPLACE_PERL+=	tools/modules/rollrec.pm
REPLACE_PERL+=	tools/modules/timetrans.pm
REPLACE_PERL+=	tools/modules/tooloptions.pm
REPLACE_PERL+=	tools/convertar/lib/Net/DNS/SEC/Tools/TrustAnchor/Makefile.PL

PERL5_PACKLIST=		auto/Net/DNS/SEC/Tools/Dnspktflow/dnspktflow/.packlist
PERL5_PACKLIST+=	auto/Net/DNS/SEC/Tools/Donuts/donuts/.packlist
PERL5_PACKLIST+=	auto/Net/DNS/SEC/Tools/Drawvalmap/drawvalmap/.packlist
PERL5_PACKLIST+=	auto/Net/DNS/SEC/Tools/Maketestzone/maketestzone/.packlist
PERL5_PACKLIST+=	auto/Net/DNS/SEC/Tools/Mapper/mapper/.packlist
PERL5_PACKLIST+=	auto/Net/DNS/SEC/Tools/conf/.packlist
PERL5_PACKLIST+=	auto/convertar/.packlist
PERL5_PACKLIST+=	auto/dnssec-tools/.packlist

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-nsec3
CONFIGURE_ARGS+=	--with-resolv-conf=${PKG_SYSCONFDIR}/dnssec-tools/resolv.conf
CONFIGURE_ARGS+=	--with-root-hints=${PKG_SYSCONFDIR}/dnssec-tools/root.hints
CONFIGURE_ARGS+=	--with-perl-build-args=${MAKE_PARAMS:Q}

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

EGDIR=			${PREFIX}/share/examples/dnssec-tools
PKG_SYSCONFSUBDIR?=	dnssec-tools

CONF_FILES=	${EGDIR}/dnsval.conf ${PKG_SYSCONFDIR}/dnsval.conf
CONF_FILES+=	${EGDIR}/resolv.conf ${PKG_SYSCONFDIR}/resolv.conf
CONF_FILES+=	${EGDIR}/root.hints ${PKG_SYSCONFDIR}/root.hints

INSTALLATION_DIRS=	${EGDIR}

.include "options.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/sbin/dnssec-keygen)
CONFIGURE_ARGS+=	BIND_DNSSEC_KEYGEN=/usr/sbin/dnssec-keygen
.endif
.if ${OPSYS} == "NetBSD" && exists(/usr/sbin/dnssec-signzone)
CONFIGURE_ARGS+=	BIND_DNSSEC_SIGNZONE=/usr/sbin/dnssec-signzone
.endif
.if ${OPSYS} == "NetBSD" && exists(/usr/sbin/named-checkzone)
CONFIGURE_ARGS+=	BIND_DNSSEC_CHECKZONE=/usr/sbin/named-checkzone
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/validator/etc/dnsval.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/validator/etc/resolv.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/validator/etc/root.hints ${DESTDIR}${EGDIR}

PERL5_CONFIGURE=	no
.include "../../lang/perl5/module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
