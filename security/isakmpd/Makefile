# $NetBSD: Makefile,v 1.29 2003/09/21 08:02:59 jmc Exp $
#

DISTNAME=		isakmpd-20021118
PKGREVISION=		2
WRKSRC=			${WRKDIR}/isakmpd
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

MAINTAINER=		itojun@kame.net
COMMENT=		OpenBSD IKE daemon

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
PKG_FAIL_REASON+=	"${PKGNAME} requires ipsec-ready ${OPSYS}"
.endif

ALL_TARGET=		depend all
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

MAKE_ENV+=		BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man

PKG_SYSCONFSUBDIR=	isakmpd

RCD_SCRIPTS=		isakmpd
RCD_SCRIPT_WRK.isakmpd=	${WRKDIR}/isakmpd.sh

pre-configure:
	@${ECHO_MSG} "Fixing references to buildlink directories"
	@for i in ${WRKSRC}/sysdep/netbsd/Makefile.sysdep; do		\
		${MV} $${i} $${i}.orig;					\
		${SED} "s+@BUILDLINK_PREFIX.openssl@+${BUILDLINK_PREFIX.openssl}+g" \
			< $${i}.orig > $${i};				\
	done
	@${ECHO_MSG} "Fixing references to configuration directory"
	@for i in conf.h policy.h ike_auth.h; do			\
		${MV} ${WRKSRC}/$${i} ${WRKSRC}/$${i}.orig;		\
		${SED} "s+/etc/isakmpd+${PKG_SYSCONFDIR}+g"		\
			< ${WRKSRC}/$${i}.orig > ${WRKSRC}/$${i};	\
	done
	@${ECHO_MSG} "Fixing manual page references"
	@for i in isakmpd.8 isakmpd.conf.5 isakmpd.policy.5; do		\
		${MV} ${WRKSRC}/$${i} ${WRKSRC}/$${i}.orig;		\
		${SED} -e "s+/usr/share/ipsec+${PREFIX}/share/examples+g" \
			-e "s+/etc/isakmpd+${PKG_SYSCONFDIR}+g"		\
			< ${WRKSRC}/$${i}.orig > ${WRKSRC}/$${i};	\
	done

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
