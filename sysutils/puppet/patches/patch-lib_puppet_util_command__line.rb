$NetBSD: patch-lib_puppet_util_command__line.rb,v 1.1 2016/08/26 09:26:05 fhajny Exp $

Fix subcommand handling for our suffixed bins.

--- lib/puppet/util/command_line.rb.orig	2016-08-25 13:06:40.887601145 +0000
+++ lib/puppet/util/command_line.rb
@@ -38,7 +38,7 @@ module Puppet
       # @return [String] name of the subcommand is being executed
       # @api public
       def subcommand_name
-        return @command if @command != 'puppet'
+        return @command if (@command != 'puppet' && @command != 'puppet@RUBY_SUFFIX@')
 
         if @argv.first =~ OPTION_OR_MANIFEST_FILE
           nil
@@ -50,7 +50,7 @@ module Puppet
       # @return [Array<String>] the command line arguments being passed to the subcommand
       # @api public
       def args
-        return @argv if @command != 'puppet'
+        return @argv if (@command != 'puppet' && @command != 'puppet@RUBY_SUFFIX@')
 
         if subcommand_name.nil?
           @argv
