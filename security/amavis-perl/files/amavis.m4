PUSHDIVERT(-1)
#
# amavis mailer definition for amavis-perl (http://www.amavis.org)
#
# Copyright (c) 2000 Yan Seiner 
# GPL distribution - all disclaimers apply.
#
# Adopted & extented by Rainer Link, SuSE GmbH, <link@suse.de>, 03/02/2001
#
#  Currently UNTESTED
#  USE AT YOUR OWN RISK
#

ifdef(`AMAVIS_MAILER_ARGS',,
        `define(`AMAVIS_MAILER_ARGS',  amavis $f $u)')
ifdef(`AMAVIS_MAILER_PATH',,
        `define(`AMAVIS_MAILER_PATH', @PREFIX@/sbin/amavis)')
ifdef(`AMAVIS_MAILER_FLAGS',,
	`define(`AMAVIS_MAILER_FLAGS', `mlsACDFMS5:/|@qhP')')
ifdef(`AMAVIS_MAILER_USER',,
	`define(`AMAVIS_MAILER_USER', amavis)')
ifdef(`AMAVIS_MAILER_GROUP',,
	`define(`AMAVIS_MAILER_GROUP', amavis)')


POPDIVERT
#######################################
###   AMAVIS Mailer specification   ###
#######################################

VERSIONID(`@(#)amavis.m4        03/02/2001')

Mamavis,                P=AMAVIS_MAILER_PATH, F=AMAVIS_MAILER_FLAGS, S=0, R=0, 
                        T=DNS/RFC822/X-Unix,
                        ifdef(`AMAVIS_MAILER_MAX', `M=AMAVIS_MAILER_MAX, ')A=AMAVIS_MAILER_ARGS,
                        U=AMAVIS_MAILER_USER:AMAVIS_MAILER_GROUP

LOCAL_RULE_0
R$*			$#amavis $:$1

