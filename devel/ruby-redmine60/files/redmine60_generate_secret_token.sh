#!/bin/sh

cd @PREFIX@/@RM_DIR@

@RUBY@ bin/rake generate_secret_token
