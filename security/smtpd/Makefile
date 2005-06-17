# $NetBSD: Makefile,v 1.12 2005/06/17 03:50:32 jlam Exp $
#

DISTNAME=	smtpd-2.0
PKGREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	ftp://ftp.obtuse.com/pub/smtpd/

PATCHFILES=	patch-smtpd-2.0-RBL.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.obtuse.com/smtpd.html
COMMENT=	Store and forward SMTP proxy

SPOOL=		/var/spool/smtpd

# taken directly from the Makefile.
CFLAGS.NetBSD=	-DUSE_FLOCK -DUSE_MKSTEMP
CFLAGS.SunOS=	-DUSE_LOCKF -DNEEDS_FCNTL_H -DNEEDS_STRINGS_H -DBROKEN_SUN_INCLUDES
CFLAGS.IRIX=	-DGETOPT_EOF -DUSE_FLOCK -DNEEDS_FCNTL_H -DNEEDS_BSTRING_H -DIRIX_BROKEN_INCLUDES
CFLAGS.AIX=	-DGETOPT_EOF -DUSE_LOCKF -DNEEDS_FCNTL_H -DNEEDS_LOCKF_H -DNEEDS_STRINGS_H -DNEEDS_SELECT_H
OPSYSVARS=	LD_LIBS
LD_LIBS.SunOS=	-lnsl -lsocket -lresolv
MAKE_ENV+=	LD_LIBS="${LD_LIBS}"

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	sbin

do-install:
	-${INSTALL_DATA_DIR} ${SPOOL}/etc
	${INSTALL} -m 500 ${WRKSRC}/smtpd ${PREFIX}/sbin/smtpd
	${INSTALL} -m 500 ${WRKSRC}/smtpfwdd ${PREFIX}/sbin/smtpfwdd
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smtpd
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/smtpd
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/smtpd

post-install:
.for f in antirelay_check_rules_example antispam_check_rules.example \
	smtpd_check_rules.example
	${INSTALL_DATA} ${WRKSRC}/${f} ${SPOOL}/etc
.endfor
	${CHOWN} -R uucp ${SPOOL}
	${CHGRP} -R mail ${SPOOL}
	${CHMOD} -R g=,o= ${SPOOL}
	${CP} /etc/resolv.conf ${SPOOL}/etc
.if ${OPSYS} == "SunOS"
	${CP} /etc/TIMEZONE ${SPOOL}/etc
.else
	${CP} /etc/localtime ${SPOOL}/etc
.endif

.include "../../mk/bsd.pkg.mk"
