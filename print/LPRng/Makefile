# New ports collection makefile for:	LPRng
# Version required:	3.6.6
# Date created:		2 Apr 1997
# Whom:			desmo@bandwidth.org
#
# $Id: Makefile,v 1.1.1.1 1999/09/11 21:58:30 jlam Exp $
#

DISTNAME=	LPRng-3.6.6
CATEGORIES=	sysutils print
MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} LPRng_DOC-3.6.6.tgz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	desmo@bandwidth.org

MAKEFILE=	Makefile.bsd
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= \
 --with-lpddir=${PREFIX}/sbin \
 --with-admindir=${PREFIX}/sbin \
 --with-filterdir=${PREFIX}/libexec/filters \
 --with-lpd_conf_path=/etc/lpd.conf \
 --with-lpd_perms_path=/etc/lpd.perms \
 --with-printcap_path=/etc/printcap

MAN1=		cancel.1 lp.1 lpbanner.1 lpc.1 lpf.1 \
		lpq.1 lpr.1 lpraccnt.1 lprm.1 lpstat.1 monitor.1
MAN5=		lpd.conf.5 lpd.perms.5 printcap.5
MAN8=		checkpc.8 lpd.8
MANCOMPRESSED=	yes

post-install:
	${CAT} ${FILESDIR}/lprng.sh | \
		${SED} -e "s|@@PREFIX@@|${PREFIX}|g" > ${PREFIX}/etc/rc.d/lprng.sh
	chmod +x ${PREFIX}/etc/rc.d/lprng.sh
	${INSTALL} -d -g bin -o bin -m 0555 ${PREFIX}/share/doc/LPRng
	@for file in ${EXTRA_FILES}; do \
		${CP} ${DISTDIR}/$$file ${PREFIX}/share/doc/LPRng; \
		cd ${PREFIX}/share/doc/LPRng; \
		tar xvfz $$file; \
		${RM} ${PREFIX}/share/doc/LPRng/$$file; \
	done
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
