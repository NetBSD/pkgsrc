# $NetBSD: Makefile,v 1.2 2004/06/22 16:08:27 hamajima Exp $
#

DISTNAME=	dtcp-20030228
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.imasy.or.jp/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~ume/dtcp/
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client

DEPENDS+=	ruby-digest-*:../../security/ruby-digest
DEPENDS+=	qpopper-*:../../mail/qpopper

RCD_SCRIPTS=	dtcpc dtcps
CONF_DEPENDS=	YES

post-configure:
	@cd ${WRKSRC} && \
	for f in dtcpauth.8 dtcpc.8 dtcps.8 ; do		\
		${MV} $$f $$f.orig;				\
		${SED} 's|/usr/local|${PREFIX}|g' $$f.orig > $$f;	\
	done

.include "../../mk/bsd.pkg.mk"
