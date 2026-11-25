# $NetBSD: apache.mk,v 1.35 2026/11/25 17:01:23 wiz Exp $
#
# This file is meant to be included by packages that require an apache
# web server.

.if !defined(APACHE_MK)
APACHE_MK=			# defined

.include "../../www/apache24/buildlink3.mk"
.endif	# APACHE_MK
