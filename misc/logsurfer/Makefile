# New ports collection makefile for:	logsurfer
# Version required:	1.41
# Date created:		28 Jul 1996
# Whom:			shanee@rabbit.augusta.de
#
# $NetBSD: Makefile,v 1.5 1998/02/04 20:41:05 frueauf Exp $
# FreeBSD Id: Makefile,v 1.2 1997/10/26 23:56:58 fenner Exp
#

DISTNAME=	logsurfer-1.41
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.fh-rosenheim.de/pub/mirror/cert.dfn/tools/audit/logsurfer/ \
		ftp://ftp.tuwien.ac.at/infosys/security/dfn/tools/audit/logsurfer/ \
		ftp://ftp.uni-magdeburg.de/pub/mirror/ftp.cert.dfn.de/tools/audit/logsurfer/

MAINTAINER=	shanee@rabbit.augusta.de

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/etc

MANCOMPRESSED=	yes
MAN1=		logsurfer.1
MAN4=		logsurfer.conf.4

.include <bsd.port.mk>
