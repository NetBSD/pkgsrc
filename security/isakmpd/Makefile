# $NetBSD: Makefile,v 1.21 2002/08/30 07:40:00 martti Exp $
#

DISTNAME=		isakmpd-20020830
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

MAINTAINER=		itojun@kame.net
COMMENT=		OpenBSD IKE daemon

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
IGNORE+=		"${PKGNAME} requires ipsec-ready NetBSD"
.endif

ALL_TARGET=		depend all

WRKSRC=			${WRKDIR}/isakmpd

MAKE_ENV+=		BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man

post-patch:
	@${ECHO_MSG} "Fixing references to buildlink directories"
	@for i in `${FIND} ${WRKSRC} -name '*Makefile*'`; do		\
		${MV} $${i} $${i}.orig;					\
		${SED} "s+@BUILDLINK_DIR@+${BUILDLINK_DIR}+g"		\
			< $${i}.orig > $${i};				\
	done
	@${ECHO_MSG} "Fixing manual page references"
	@for i in isakmpd.8 isakmpd.conf.5 isakmpd.policy.5; do		\
		${MV} ${WRKSRC}/$${i} ${WRKSRC}/$${i}.orig;		\
		${SED} "s+/usr/share/ipsec+${PREFIX}/share/examples+g"	\
			< ${WRKSRC}/$${i}.orig > ${WRKSRC}/$${i};	\
	done

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/isakmpd.sh > ${WRKDIR}/isakmpd.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/isakmpd.sh ${PREFIX}/etc/rc.d/isakmpd

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
